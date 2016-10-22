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
    public partial class KeybdWinKeyEForm : Form
    {
        public KeybdWinKeyEForm()
        {
            InitializeComponent();
            this.CenterToScreen();
            KeybdAltF4Box.Image = Image.FromFile("C:\\Users\\mango.DGSSM\\Documents\\Visual Studio 2013\\Projects\\ExplainGlove\\ExplainGlove\\invermode-windowkey+M.gif");
            KeybdAltF4Box.Visible = true;

        }

        private void KeybdAltF4Box_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
