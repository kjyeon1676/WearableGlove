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
    public partial class OKmode : Form
    {
        public OKmode()
        {
            InitializeComponent();
            this.CenterToScreen();
            okModePicBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\DragAndPPt.gif");
            okModePicBox.Visible = true;
        }

        private void okModePicBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
