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
    public partial class MouseWheelForm : Form
    {
        public MouseWheelForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            MouseWheelBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\mouseWheel.gif");
            MouseWheelBox.Visible = true;
        }

        private void MouseWheelBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
