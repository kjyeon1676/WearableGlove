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
    public partial class KeybdAltEscForm : Form
    {
        public KeybdAltEscForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            KeybdAltEscBox.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\invermode-windowkey+E.gif");
            KeybdAltEscBox.Visible = true;

        }

        private void KeybdAltEscBox_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
