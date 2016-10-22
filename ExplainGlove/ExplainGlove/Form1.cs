using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace ExplainGlove
{
    public partial class Form1 : Form
    {
        public Form1 mainForm;
        private Point mousePoint;
        private StartPicForm StartForm;
        private MouseWheelForm mouseWheelForm;
        private MouseDbClickForm mouseDbClickForm;
        private KeybdWinKeyEForm keybdAltF4Form;
        private KeybdAltEscForm keybdAltEscForm;
        private KeybdAltTabForm keybdAltTabForm;
        private WindowKeyForm windowKeyForm;
        private AirCommandForm airCommandForm;
        private ExplainTwo explainTwoForm;
        private OKmode okModeForm;
        public Form1()
        {
            InitializeComponent();
            this.BackColor = Color.White;
            basicGroupBox.BackColor = Color.Transparent;
            keybdGroupBox.BackColor = Color.Transparent;
            startGroupBox.BackColor = Color.Transparent;
            FirstMeuText.BackColor = Color.Transparent;

        }
        private void label4_Click(object sender, EventArgs e)
        {
            StartForm = new StartPicForm();
            StartForm.Owner = this;
            StartForm.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Abort;
            Application.Exit();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if ((e.Button & MouseButtons.Left) == MouseButtons.Left)
            {
                Location = new Point(this.Left - (mousePoint.X - e.X),
                    this.Top - (mousePoint.Y - e.Y));
            }
        }

        private void Form1_DoubleClick(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Maximized)
            {
                this.WindowState = FormWindowState.Normal;
            }
            else
            {
                this.WindowState = FormWindowState.Maximized;
            }

        }

        private void MouseClickText_Click(object sender, EventArgs e)
        {
            
        }

        private void MouseRClickText_Click(object sender, EventArgs e)
        {
           
        }

        private void MouseWheelText_Click(object sender, EventArgs e)
        {
            mouseWheelForm = new MouseWheelForm();
            mouseWheelForm.Owner = this;
            mouseWheelForm.Show();
        }

        private void MouseDbClickText_Click(object sender, EventArgs e)
        {
            mouseDbClickForm = new MouseDbClickForm();
            mouseDbClickForm.Owner = this;
            mouseDbClickForm.Show();
        }

        private void KeybdAltF4Text_Click(object sender, EventArgs e)
        {
            keybdAltF4Form = new KeybdWinKeyEForm();
            keybdAltF4Form.Owner = this;
            keybdAltF4Form.Show();
        }

        private void KeybdAltEscText_Click(object sender, EventArgs e)
        {
            keybdAltEscForm = new KeybdAltEscForm();
            keybdAltEscForm.Owner = this;
            keybdAltEscForm.Show();
        }

        private void KeybdAltTabText_Click(object sender, EventArgs e)
        {
            keybdAltTabForm = new KeybdAltTabForm();
            keybdAltTabForm.Owner = this;
            keybdAltTabForm.Show();
        }

        private void WindowKey_Click(object sender, EventArgs e)
        {
            windowKeyForm = new WindowKeyForm();
            windowKeyForm.Owner = this;
            windowKeyForm.Show();
        }

        private void AirCommandText_Click(object sender, EventArgs e)
        {
            airCommandForm = new AirCommandForm();
            airCommandForm.Owner = this;
            airCommandForm.Show();
        }

        private void ExitText_Click(object sender, EventArgs e)
        {
           
        }

        private void MouseClickText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void MouseClickText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void MouseRClickText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void MouseRClickText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void label4_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void label4_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void MouseWheelText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void MouseWheelText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void MouseDbClickText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void MouseDbClickText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void AirCommandText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void AirCommandText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void ExitText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void ExitText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void KeybdAltF4Text_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void KeybdAltF4Text_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void KeybdAltEscText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void KeybdAltEscText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void KeybdAltTabText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void KeybdAltTabText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void WindowKey_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void WindowKey_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void NextPageBtn1_Click(object sender, EventArgs e)
        {
            explainTwoForm = new ExplainTwo();
            explainTwoForm.Owner = this;
            explainTwoForm.Show();
            this.Visible = false;
        }

        private void OKModeText_Click(object sender, EventArgs e)
        {
            okModeForm = new OKmode();
            okModeForm.Owner = this;
            okModeForm.Show();
        
        }

        private void OKModeText_MouseMove(object sender, MouseEventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void OKModeText_MouseLeave(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }
    }
}
//마우스 왼쪽
//마우스 우클릭
//마우스 더블클릭
//마우스 휠
//드래그
//윈탭
//퀵메뉴
//피피티 넘기는 왼쪽 오른쪽 - 링모션, Alt+f4 
//on / off 시작 끄는거
//inverse Mode - 가운데 손가락 : 바탕화면 Win + m
//             - 약지 : 탐색기 win + e
//             - 링 모양 : 종료
//Normal Mode  - 검지 : 왼쪽클릭
//             - 더블클릭 : 검지 다음 중지
//             - 중지 : 마우스 오른쪽 클릭
//             - 전화기모양손 : 휠
//             - 링모양 : 드래그
//side Mode    - 가운데 손가락 : win+tab 손방향 위로 하면 위로, 아래로 하면 아래로 내려가는거.. 선택
//             - 약지 : Quick Menu
//ok Mode      - 화살표 왼쪽 오른쪽