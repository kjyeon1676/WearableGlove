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
    public partial class ExitForm : Form
    {
        public ExitForm()
        {
            InitializeComponent();
            ExitBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Desktop\\테스트중\\tested.png");
            ExitBox.Visible = true;
        }

        private void ExitBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
