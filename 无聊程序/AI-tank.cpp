/**
 * 围绕对手作来回的移动，并在此基础上添加了与对手保持一定距离，不撞墙的功能，
 * 并且运动带有随机性。
 * @author xiemin
 */
#include <airobot/c/SimpleRobot.h>

//理想距离
#define PREFER_DISTANCE 300
//计算目标点时采用的搜索半径
#define SEARCH_DIS 100
//每次迭代的递增量
#define GAP toRadians(5)
//离墙的距离
#define AWAY_FROM_WALL 50
#define MATCH_LENGHT 20
#define HISTORY_LENGHT 2000

//移动的方向,这个变量的值只能取1和-1，1表示前进，-1表示后退
int direction = 1;
//在一个方向上最大的移动时间
long maxTime = 30;
//当前在一个方向上的移动时间
long moveTime = 0;
double the_angle =0;
typedef struct jilu   //记录
{
    double vR;  //velocityRecord
    double hR;  //headingRecord
} jL;

jL rcd[HISTORY_LENGHT];
//记录当前位置
int currentIndex;
//记录当前的机器人状态
void record(struct Bot* bot);
//计算最佳的匹配点
int getMatchIndex();
//得到开火的位置
void getFirePoint(int matchIndex, double power, double* fireX, double* fireY);


//设置移动的方向
void setDirection(void);
//执行移动
void doMove(void);
//执行转动
void doTurn(void);
//得到圆心位置
void getCenter(double* x, double* y);
//得到用于保持理想距离的修正角deltaAngle
double getDeltaAngle(double centerX, double centerY);
//得到用来修正移动方向避免机器人撞墙的夹角needTurn
double getNeedTurn(double headingTo);
//判断给定的点是否是一个有效的目标点
int isValid(double x, double y);
void shoot_tank();
void set_power();
//开火时的炮弹能量
double POWER =0.5;
//对手上个单位时间的方向
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
        //初始化迭代
        nextHeading = opponent->heading;
        nextX = opponent->x;
        nextY = opponent->y;
        _time = 0;
        //判断子弹在time时间后能否打到在next位置的对手
        dis = distance(nextX, nextY, getX(), getY());
        //进入迭代
        while(1)
        {
            if(dis/getBulletVelocity(POWER)<=_time)
            {
                //能打到，迭代结束
                fireOnPoint(nextX, nextY, POWER); //开火
                break;
            }
            //进入下一次迭代
            _time ++;
            nextHeading += bea;
            //计算在下个时间对手的位置
            nextPoint(nextX, nextY, nextHeading, opponent->velocity, &nextX, &nextY);
        }
        lastHeading = opponent->heading;
    }
}

//记录当前的机器人状态
void record(struct Bot* bot)
{
    rcd[currentIndex].vR = bot->velocity;
    rcd[currentIndex].hR = bot->heading;
    currentIndex++;
    return;
}

//计算最佳的匹配点
int getMatchIndex()
{
    double beatSimilarity=1000000;
    int matchIndex=0, i, j;
    //这里取i<currentFrame-100是为了避免比较样本和被比较样本重复
    //和留取足够的节点给递推未来坐标用
    for(i=MATCH_LENGHT; i<currentIndex-MATCH_LENGHT; i++)
    {
        //取10个样本节点计算相似度
        double similarity=0;
        for(j=1; j<=MATCH_LENGHT; j++)
        {
            similarity+=fabs(rcd[i-j].vR-rcd[currentIndex-j].vR)/8;
            similarity+=fabs(rcd[i-j].hR-rcd[currentIndex-j].hR)/PI;
        }
        //记录最相似的相似度，以及对应的记录节点下标
        if(similarity<beatSimilarity)
        {
            matchIndex=i;
            beatSimilarity=similarity;
        }
    }
    return matchIndex;
}

//得到开火的位置
void getFirePoint(int matchIndex, double power, double* fireX, double* fireY)
{
    //预测位置
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
        //随机生成在这个方向上移动的时间
        maxTime = rand()%60;
        //改变运动方向
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
    //为了保持距离用deltaAngle对headingTo进行修正
    deltaAngle = getDeltaAngle(centerX, centerY);
    headingTo -= deltaAngle;
    //为了不撞墙用needTurn对headingTo进行修正
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
    //进入迭代
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

//启动机器人程序
int main(int argC, char* argV[])
{
    tickHook = onTick;
    roundBeginHook = onRoundBegin;
    return startup(argC, argV);
}
