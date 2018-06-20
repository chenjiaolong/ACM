/**
 * Χ�ƶ��������ص��ƶ������ڴ˻��������������ֱ���һ�����룬��ײǽ�Ĺ��ܣ�
 * �����˶���������ԡ�
 * @author xiemin
 */
#include <airobot/c/SimpleRobot.h>

//�������
#define PREFER_DISTANCE 300
//����Ŀ���ʱ���õ������뾶
#define SEARCH_DIS 100
//ÿ�ε����ĵ�����
#define GAP toRadians(5)
//��ǽ�ľ���
#define AWAY_FROM_WALL 50
#define MATCH_LENGHT 20
#define HISTORY_LENGHT 2000

//�ƶ��ķ���,���������ֵֻ��ȡ1��-1��1��ʾǰ����-1��ʾ����
int direction = 1;
//��һ�������������ƶ�ʱ��
long maxTime = 30;
//��ǰ��һ�������ϵ��ƶ�ʱ��
long moveTime = 0;
double the_angle =0;
typedef struct jilu   //��¼
{
    double vR;  //velocityRecord
    double hR;  //headingRecord
} jL;

jL rcd[HISTORY_LENGHT];
//��¼��ǰλ��
int currentIndex;
//��¼��ǰ�Ļ�����״̬
void record(struct Bot* bot);
//������ѵ�ƥ���
int getMatchIndex();
//�õ������λ��
void getFirePoint(int matchIndex, double power, double* fireX, double* fireY);


//�����ƶ��ķ���
void setDirection(void);
//ִ���ƶ�
void doMove(void);
//ִ��ת��
void doTurn(void);
//�õ�Բ��λ��
void getCenter(double* x, double* y);
//�õ����ڱ�����������������deltaAngle
double getDeltaAngle(double centerX, double centerY);
//�õ����������ƶ�������������ײǽ�ļн�needTurn
double getNeedTurn(double headingTo);
//�жϸ����ĵ��Ƿ���һ����Ч��Ŀ���
int isValid(double x, double y);
void shoot_tank();
void set_power();
//����ʱ���ڵ�����
double POWER =0.5;
//�����ϸ���λʱ��ķ���
double lastHeading;

void onTick(struct TickAction* action)
{
    set_power();
    shoot_tank();
    setDirection();
    doMove();
    doTurn();
}

void set_power()
{
    struct Bot* bot = getFirstOpponent();
    double nx=bot->x,ny=bot->y;
    double dis = distance(nx,ny, getX(), getY());
    if(currentIndex<60)
    {
        POWER=0.5;
    }
    else
    {
        if(dis >600)
        {
            POWER = 0.1;
            return;
        }
        else
        {
            if(dis <150)
            {
                POWER = 3;
                return;
            }
            else
            {
                POWER = 1.5;
                return;
            }
        }
    }
    return;
}

void shoot_tank()
{
    int matchIndex;
    double fireX, fireY;
    double nextX, nextY, dis, bea, nextHeading;
    long _time;
    struct Bot* opponent = getFirstOpponent();
    if(opponent==NULL) return;
    if(currentIndex>60)
    {
        record(opponent);
        matchIndex = getMatchIndex();
        getFirePoint(matchIndex, POWER, &fireX, &fireY);
        fireOnPoint(fireX, fireY, POWER);
        return;
    }
    else
    {
        bea = bearing(opponent->heading, lastHeading);
        //��ʼ������
        nextHeading = opponent->heading;
        nextX = opponent->x;
        nextY = opponent->y;
        _time = 0;
        //�ж��ӵ���timeʱ����ܷ����nextλ�õĶ���
        dis = distance(nextX, nextY, getX(), getY());
        //�������
        while(1)
        {
            if(dis/getBulletVelocity(POWER)<=_time)
            {
                //�ܴ򵽣���������
                fireOnPoint(nextX, nextY, POWER); //����
                break;
            }
            //������һ�ε���
            _time ++;
            nextHeading += bea;
            //�������¸�ʱ����ֵ�λ��
            nextPoint(nextX, nextY, nextHeading, opponent->velocity, &nextX, &nextY);
        }
        lastHeading = opponent->heading;
    }
}

//��¼��ǰ�Ļ�����״̬
void record(struct Bot* bot)
{
    rcd[currentIndex].vR = bot->velocity;
    rcd[currentIndex].hR = bot->heading;
    currentIndex++;
    return;
}

//������ѵ�ƥ���
int getMatchIndex()
{
    double beatSimilarity=1000000;
    int matchIndex=0, i, j;
    //����ȡi<currentFrame-100��Ϊ�˱���Ƚ������ͱ��Ƚ������ظ�
    //����ȡ�㹻�Ľڵ������δ��������
    for(i=MATCH_LENGHT; i<currentIndex-MATCH_LENGHT; i++)
    {
        //ȡ10�������ڵ�������ƶ�
        double similarity=0;
        for(j=1; j<=MATCH_LENGHT; j++)
        {
            similarity+=fabs(rcd[i-j].vR-rcd[currentIndex-j].vR)/8;
            similarity+=fabs(rcd[i-j].hR-rcd[currentIndex-j].hR)/PI;
        }
        //��¼�����Ƶ����ƶȣ��Լ���Ӧ�ļ�¼�ڵ��±�
        if(similarity<beatSimilarity)
        {
            matchIndex=i;
            beatSimilarity=similarity;
        }
    }
    return matchIndex;
}

//�õ������λ��
void getFirePoint(int matchIndex, double power, double* fireX, double* fireY)
{
    //Ԥ��λ��
    double x = getFirstOpponent()->x;
    double y = getFirstOpponent()->y;
    double dis;
    int time = 0;
    while(matchIndex+time<currentIndex)
    {
        dis = distance(getX(), getY(), x, y);
        if(dis/getBulletVelocity(power)<=time) break;
        nextPoint(x, y, rcd[matchIndex+time].hR,
                  rcd[matchIndex+time].vR, &x, &y);
        time++;
    }
    *fireX = x;
    *fireY = y;
}

void setDirection(void)
{
    moveTime++;
    if(moveTime>=maxTime)
    {
        moveTime=0;
        //�������������������ƶ���ʱ��
        maxTime = rand()%60;
        //�ı��˶�����
        if(rand()%10>1)
        {
            direction *= -1;
        }
    }
}

void doMove(void)
{
    double v;
    v=5+(float)(rand()%5);
    move(v*direction);
}

void doTurn(void)
{
    double centerX, centerY, lineHeading, headingTo, deltaAngle, needTurn, bea;
    struct Bot* bot = getFirstOpponent();
    double the_energy = bot->energy;
    if(getEnergy()-the_energy> 0)
    {
        the_angle = 0.5*(rand()%3);
    }
    else
    {
        the_angle = 0.05*(rand()%4);
    }
    getCenter(&centerX, &centerY);
    lineHeading = heading(getX(), getY(), centerX, centerY);
    headingTo = lineHeading + PI/2-the_angle;
    //Ϊ�˱��־�����deltaAngle��headingTo��������
    deltaAngle = getDeltaAngle(centerX, centerY);
    headingTo -= deltaAngle;
    //Ϊ�˲�ײǽ��needTurn��headingTo��������
    needTurn = getNeedTurn(headingTo);
    headingTo -= needTurn;

    bea = bearing(headingTo, getHeading());
    turn(bea);
}

void getCenter(double* x, double* y)
{
    struct Bot* bot = getFirstOpponent();
    if(bot==NULL)
    {
        *x = getCourtWidth()/2;
        *y = getCourtHeight()/2;
    }
    else
    {
        *x = bot->x;
        *y = bot->y;
    }
}

double getDeltaAngle(double centerX, double centerY)
{
    double dis = distance(centerX, centerY, getX(), getY());
    double deltaDistance = dis-PREFER_DISTANCE;
    //deltaDistance = deltaDistance/fmax(distance, PREFER_DISTANCE);
    deltaDistance = deltaDistance/500;
    return direction*PI/3*deltaDistance;
}

double getNeedTurn(double headingTo)
{
    double needTurn = 0, nextX, nextY;
    //�������
    while(1)
    {
        nextPoint(getX(), getY(), headingTo-needTurn,
                  direction*SEARCH_DIS, &nextX, &nextY);
        if(isValid(nextX, nextY)) break;
        needTurn += direction*GAP;
    }
    return needTurn;
}

int isValid(double x, double y)
{
    return inCourt(x, y, AWAY_FROM_WALL);
}

void onRoundBegin(struct RoundBeginAction* action)
{
    srand((int)time(0));
    currentIndex = 0;
}

//���������˳���
int main(int argC, char* argV[])
{
    tickHook = onTick;
    roundBeginHook = onRoundBegin;
    return startup(argC, argV);
}
