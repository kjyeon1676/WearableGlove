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
    public partial class MouseRClickForm : Form
    {
        public MouseRClickForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            MouseRClickBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Desktop\\테스트중\\tested.png");
            MouseRClickBox.Visible = true;
        }

        private void MouseRClickBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
