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
    public partial class AirCommandForm : Form
    {
        public AirCommandForm()
        {
            InitializeComponent();
            AirCommandBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\sidemode-win+tab.gif");
            AirCommandBox.Visible = true;
        }

        private void AirCommandBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
