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
    public partial class MouseDbClickForm : Form
    {
        public MouseDbClickForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            MouseDbClickBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\mouseDBClick.gif");
            MouseDbClickBox.Visible = true;

        }

        private void MouseDbClickBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
