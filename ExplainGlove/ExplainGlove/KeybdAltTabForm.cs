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
    public partial class KeybdAltTabForm : Form
    {
        public KeybdAltTabForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            KeybdAltTabBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\invermode-Alt+f4.gif");
            KeybdAltTabBox.Visible = true;
        }

        private void KeybdAltTabBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
