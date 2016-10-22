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
    public partial class WindowKeyForm : Form
    {
        public WindowKeyForm()
        {
            InitializeComponent();
            WindowKeyBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Desktop\\테스트중\\tested.png");
            WindowKeyBox.Visible = true;

        }

        private void WindowKeyBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
