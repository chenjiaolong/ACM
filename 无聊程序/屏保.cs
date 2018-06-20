using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace //�������
{
public partial class FrmProtect : Form
{
    public FrmProtect()
    {
        InitializeComponent();
    }

    /* �˳������İ�ť�ĵ�����¼� */
    /* �ð�ť�����ʱ���˳������������� */
    private void BtnClose_Click(object sender, EventArgs e)
    {
        //�رյ�ǰ�Ĵ���
        //this.Close();

        //�˳�Ӧ�ó���
        Application.Exit();
    }

    /* ����ļ����¼��������Ѿ������������ǻ�δ��ʾ�� */
    private void FrmProtect_Load(object sender, EventArgs e)
    {
        //����ť���õ���Ļ��࣬�����û��޷�������
        BtnClose.Left = -BtnClose.Width;

        //�����ò����İ�ťҲ�ƶ�����Ļ���
        BtnOption.Left = -BtnOption.Width;

        //����¡ͼƬ���ƶ�����Ļ��࣬�����û��޷�����
        //���õ�һ��ͼƬ��͵ڶ���ͼƬ��֮��ľ���ǡ��Ϊ������Ļ�Ŀ��
        PicClone.Left = Pic1.Left - screenWidth;
        PicClone.Top = Pic1.Top;
    }

    //Ϊ�˱�֤������֣�ÿ�ζ�����һ���µ�����
    /* ��Ϊrz������������������кܶ�ط���Ҫʹ�ã�Ϊ�˱���ÿ�ζ������µĹ��� */
    /* ��ô�����ǽ��������ת��Ϊȫ�ֱ���������ֻ�ᴴ��һ������ */
    Random r = new Random();

    /* ����ͼƬ�������ʽ�ƶ� */
    private void TmrRandom_Tick(object sender, EventArgs e)
    {
        //Ϊ�˱�֤ͼƬ��λ�ò�������Ļ�ķ�Χ
        int ��Ļ���=System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width;
        int ��Ļ�߶� = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Height;

        //��ͼƬ�ĺ�����������Ļ��Χ֮���������
        int x = r.Next(0, ��Ļ��� - Pic1.Width + 1);

        //��ͼƬ��������������Ļ��Χ֮���������
        int y = r.Next(0, ��Ļ�߶� - Pic1.Height + 1);

        //����һ���µ������
        Point p = new Point(x, y);

        //ֱ����ͼƬ�ƶ���ָ���ĵ�
        Pic1.Location = p;
    }

    /// <summary>
    /// ��Ļ���ܿ��
    /// </summary>
    int screenWidth = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width;

    /// <summary>
    /// ��Ļ���ܸ߶�
    /// </summary>
    int screenHeight = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Height;

    /* ��ʾ�ߴ�ĵ���¼�������Ļ�ߴ���ʾ���� */
    private void BtnSize_Click(object sender, EventArgs e)
    {
        MessageBox.Show(screenWidth + ":" + screenHeight);

        int ���������� = System.Windows.Forms.Screen.PrimaryScreen.WorkingArea.Width;
        int ��������߶� = System.Windows.Forms.Screen.PrimaryScreen.WorkingArea.Height;
        MessageBox.Show(���������� + ":" + ��������߶�);
    }

    /// <summary>
    /// ������ƶ��ٶ�
    /// </summary>
    int speedX = 5;

    /// <summary>
    /// ������ƶ��ٶ�
    /// </summary>
    int speedY = 10;

    /* ����ͼƬ����ײ�ķ�ʽ�ƶ� */
    private void TmrBall_Tick(object sender, EventArgs e)
    {
        Pic1.Left += speedX;
        Pic1.Top += speedY;

        //�ж��Ƿ��������ұ߽�
        if (Pic1.Right >= screenWidth)
        {
            speedX = -speedX;
        }
        //�ж��Ƿ���������߽�
        else if (Pic1.Left <= 0)
        {
            speedX = -speedX;
        }

        //�ж��Ƿ��������ϱ߽�
        if (Pic1.Top <= 0)
        {
            speedY = -speedY;
        }
        //�ж��Ƿ��������±߽�
        else if (Pic1.Bottom >= screenHeight)
        {
            speedY = -speedY;
        }
    }

    /* ����ͼƬ��ѭ����ʽ�ƶ� */
    private void TmrScroll_Tick(object sender, EventArgs e)
    {
        Pic1.Left += speedX;

        //�ж��Ƿ��Ѿ���ȫ�Ƴ�����Ļ
        if (Pic1.Left >= screenWidth)
        {
            Pic1.Left = -Pic1.Width;

            //ÿ���л�λ�õ�ʱ�򣬽�ͼƬ�������ƶ�
            Pic1.Top += 100;
        }

        //�ж�ͼƬ���Ƿ����±߽�
        if (Pic1.Bottom >= screenHeight)
        {
            Pic1.Top = 0;
        }
    }

    /* ����2��ͼƬ����������� */
    private void TmrContinue_Tick(object sender, EventArgs e)
    {
        //��2��ͼƬ������ͬ���ٶ��ƶ�
        Pic1.Left += speedX;
        PicClone.Left += speedX;

        //�жϵ�һ��ͼƬ���Ƿ��Ѿ���ȫ�Ƴ�����Ļ
        if (Pic1.Left >= screenWidth)
        {
            Pic1.Left = PicClone.Left - screenWidth;
        }

        //�жϿ�¡��ͼƬ���Ƿ��Ѿ���ȫ�Ƴ���Ļ
        if (PicClone.Left >= screenWidth)
        {
            PicClone.Left = Pic1.Left - screenWidth;
        }
    }

    /* ͼƬ�������б�򣺸ı�ѡ��ʱ���ı�ͼƬ���е�ͼƬ */
    private void CboImage_SelectedIndexChanged(object sender, EventArgs e)
    {
        string image = CboImage.Text;

        if (image != "��ѡ��")
        {
            Pic1.ImageLocation = image + ".jpg";
        }
    }

    /* ���ò����İ�ť�����ʱ�������ò����������ʾ���� */
    private void BtnOption_Click(object sender, EventArgs e)
    {
        int x = (screenWidth - GrpOption.Width) / 2;
        int y = (screenHeight - GrpOption.Height) / 2;

        GrpOption.Location = new Point(x, y);

        GrpOption.Visible = !GrpOption.Visible;
    }

    /* ����ͼƬ�������ʽ�ƶ��ĵ�ѡ��ť */
    private void RadRandom_CheckedChanged(object sender, EventArgs e)
    {
        //�ж�����ĵ�ѡ��ť�Ƿ�ѡ��
        if (RadRandom.Checked)
        {
            TmrRandom.Enabled = true;

            TmrBall.Enabled = false;
            TmrContinue.Enabled = false;
            TmrScroll.Enabled = false;
        }
    }

    private void RadBall_CheckedChanged(object sender, EventArgs e)
    {
        if (RadBall.Checked)
        {
            TmrBall.Enabled = true;

            TmrRandom.Enabled = false;
            TmrContinue.Enabled = false;
            TmrScroll.Enabled = false;
        }
    }
}
}
