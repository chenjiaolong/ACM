using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace //屏保软件
{
public partial class FrmProtect : Form
{
    public FrmProtect()
    {
        InitializeComponent();
    }

    /* 退出屏保的按钮的点击的事件 */
    /* 该按钮被点击时：退出整个屏保程序 */
    private void BtnClose_Click(object sender, EventArgs e)
    {
        //关闭当前的窗体
        //this.Close();

        //退出应用程序
        Application.Exit();
    }

    /* 窗体的加载事件（窗体已经被创建，但是还未显示） */
    private void FrmProtect_Load(object sender, EventArgs e)
    {
        //将按钮设置到屏幕外侧，这样用户无法看到了
        BtnClose.Left = -BtnClose.Width;

        //将设置参数的按钮也移动到屏幕外侧
        BtnOption.Left = -BtnOption.Width;

        //将克隆图片框移动到屏幕外侧，这样用户无法看到
        //设置第一个图片框和第二个图片框之间的距离恰好为整个屏幕的宽度
        PicClone.Left = Pic1.Left - screenWidth;
        PicClone.Top = Pic1.Top;
    }

    //为了保证随机出现，每次都产生一个新的坐标
    /* 因为rz这个工具在整个程序中很多地方都要使用，为了避免每次都创建新的工具 */
    /* 那么，我们将这个工具转换为全局变量，这样只会创建一个工具 */
    Random r = new Random();

    /* 控制图片以随机方式移动 */
    private void TmrRandom_Tick(object sender, EventArgs e)
    {
        //为了保证图片的位置不超出屏幕的范围
        int 屏幕宽度=System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width;
        int 屏幕高度 = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Height;

        //让图片的横向坐标在屏幕范围之内随机出现
        int x = r.Next(0, 屏幕宽度 - Pic1.Width + 1);

        //让图片的纵向坐标在屏幕范围之内随机出现
        int y = r.Next(0, 屏幕高度 - Pic1.Height + 1);

        //创建一个新的坐标点
        Point p = new Point(x, y);

        //直接让图片移动到指定的点
        Pic1.Location = p;
    }

    /// <summary>
    /// 屏幕的总宽度
    /// </summary>
    int screenWidth = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width;

    /// <summary>
    /// 屏幕的总高度
    /// </summary>
    int screenHeight = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Height;

    /* 显示尺寸的点击事件：将屏幕尺寸显示出来 */
    private void BtnSize_Click(object sender, EventArgs e)
    {
        MessageBox.Show(screenWidth + ":" + screenHeight);

        int 工作区域宽度 = System.Windows.Forms.Screen.PrimaryScreen.WorkingArea.Width;
        int 工作区域高度 = System.Windows.Forms.Screen.PrimaryScreen.WorkingArea.Height;
        MessageBox.Show(工作区域宽度 + ":" + 工作区域高度);
    }

    /// <summary>
    /// 横向的移动速度
    /// </summary>
    int speedX = 5;

    /// <summary>
    /// 纵向的移动速度
    /// </summary>
    int speedY = 10;

    /* 控制图片以碰撞的方式移动 */
    private void TmrBall_Tick(object sender, EventArgs e)
    {
        Pic1.Left += speedX;
        Pic1.Top += speedY;

        //判断是否碰到了右边界
        if (Pic1.Right >= screenWidth)
        {
            speedX = -speedX;
        }
        //判断是否碰到了左边界
        else if (Pic1.Left <= 0)
        {
            speedX = -speedX;
        }

        //判断是否碰到了上边界
        if (Pic1.Top <= 0)
        {
            speedY = -speedY;
        }
        //判断是否碰到了下边界
        else if (Pic1.Bottom >= screenHeight)
        {
            speedY = -speedY;
        }
    }

    /* 控制图片以循环方式移动 */
    private void TmrScroll_Tick(object sender, EventArgs e)
    {
        Pic1.Left += speedX;

        //判断是否已经完全移出了屏幕
        if (Pic1.Left >= screenWidth)
        {
            Pic1.Left = -Pic1.Width;

            //每次切换位置的时候，将图片框向下移动
            Pic1.Top += 100;
        }

        //判断图片框是否到了下边界
        if (Pic1.Bottom >= screenHeight)
        {
            Pic1.Top = 0;
        }
    }

    /* 控制2个图片框的连续滚动 */
    private void TmrContinue_Tick(object sender, EventArgs e)
    {
        //让2个图片框以相同的速度移动
        Pic1.Left += speedX;
        PicClone.Left += speedX;

        //判断第一个图片框是否已经完全移出了屏幕
        if (Pic1.Left >= screenWidth)
        {
            Pic1.Left = PicClone.Left - screenWidth;
        }

        //判断克隆的图片框是否已经完全移出屏幕
        if (PicClone.Left >= screenWidth)
        {
            PicClone.Left = Pic1.Left - screenWidth;
        }
    }

    /* 图片的下拉列表框：改变选项时，改变图片框中的图片 */
    private void CboImage_SelectedIndexChanged(object sender, EventArgs e)
    {
        string image = CboImage.Text;

        if (image != "请选择")
        {
            Pic1.ImageLocation = image + ".jpg";
        }
    }

    /* 设置参数的按钮被点击时，将设置参数的面板显示出来 */
    private void BtnOption_Click(object sender, EventArgs e)
    {
        int x = (screenWidth - GrpOption.Width) / 2;
        int y = (screenHeight - GrpOption.Height) / 2;

        GrpOption.Location = new Point(x, y);

        GrpOption.Visible = !GrpOption.Visible;
    }

    /* 控制图片以随机方式移动的单选按钮 */
    private void RadRandom_CheckedChanged(object sender, EventArgs e)
    {
        //判断随机的单选按钮是否被选中
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
