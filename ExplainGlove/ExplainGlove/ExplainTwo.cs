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
    public partial class ExplainTwo : Form
    {
        private Form1 mainForm;
        public ExplainTwo()
        {
            InitializeComponent();
            FreqGroupBox.BackColor = Color.Transparent;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            mainForm = new Form1();
            mainForm.Owner = this;
            mainForm.Show();
            this.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Abort;
            Application.Exit();
            
        }
    }
}
