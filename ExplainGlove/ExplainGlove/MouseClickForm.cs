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
    public partial class MouseClickForm : Form
    {
        public MouseClickForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            MouseClickBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\StartExit.gif");
            MouseClickBox.Visible = true;
        }

        private void MouseClickBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
