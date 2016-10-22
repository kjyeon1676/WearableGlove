using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Runtime.InteropServices;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Etier.IconHelper;
using DevComponents.DotNetBar.Metro;
using DevComponents.DotNetBar;
using DevComponents.DotNetBar.Metro.ColorTables;
namespace AirCommand
{
    public partial class MainFrame : Form
    {
        /// <summary>
        /// private Variable
        /// </summary>
        private RadialMenuItem [] item;
        private const char sp = '%';
        private const char dot = '.';
        private string[] fullFilePath;
        private string[] textValue;
        private string[] splitValue;
        private string[] fileValue;
        private string[] executeValue;
        private const string path = @"C:\MagicGlove\MagicGlove.txt";
        private Icon icn;
        private Point mousePoint;

        /// <summary>
        /// Class Object
        /// </summary>
        FileExecuter exeManager = new FileExecuter();
        DirectoryInfo dirManager = new DirectoryInfo();

        /// <summary>
        /// Global Variable
        /// </summary>
        int calMinTime;
        string textFilePath;
        public MainFrame()
        {
            InitializeComponent();
            AirCommand.Diameter = 260;
            SetStyle(ControlStyles.SupportsTransparentBackColor, true);
            this.BackColor = Color.Transparent;
            //this.BackColor = Color.Transparent;
            //AirCommand.Visible = true;
            settingsMenu();
           
        }
        public void settingsMenu()
        {
            dirManager.FindCreationTime(@"C:\MagicGlove");
            textFilePath = @"C:\MagicGlove\" + dirManager.sendStr;
            textValue = System.IO.File.ReadAllLines(textFilePath);
            executeValue = new string[textValue.Length + 1];
            item = new RadialMenuItem[textValue.Length + 1];
            fileValue = new string[textValue.Length + 1];
            fullFilePath = new string[textValue.Length + 1];
            for (int i = 0; i < textValue.Length; i++)
            {
                item[i] = new RadialMenuItem();
                splitValue = textValue[i].Split(sp);
                icn = IconReader.GetFileIcon(splitValue[1], IconReader.IconSize.Large, false);
                fullFilePath[i] = splitValue[1];
                item[i].Image = icn.ToBitmap();
                fileValue = splitValue[0].Split(dot);
                item[i].Text = fileValue[0];
                executeValue[i] = fileValue[0];
                AirCommand.Items.Add(item[i]);
            }
           
        }
        private void AirCommand_ItemClick(object sender, EventArgs e)
        {
            RadialMenuItem item = sender as RadialMenuItem;
         
            if(item!=null && !string.IsNullOrEmpty(item.Text))
            {
                if (item.Text.Equals("Exit"))
                {
                    Close();
                }
                for (int i = 0; i < executeValue.Length; i++)
                {
                    if (executeValue[i].Equals(item.Text))
                    {
                        try
                        {
                            exeManager.runExcutableFile(fullFilePath[i]);
                        }
                        catch (Win32Exception ex)
                        {
                            System.Windows.Forms.MessageBox.Show("사용자가 실행을 취소했습니다");
                        }
                        break;
                    }
                }
                Close();
            }

        }

        private void AirCommand_MouseMove(object sender, MouseEventArgs e)
        {
            if ((e.Button & MouseButtons.Left) == MouseButtons.Left)
            {
                Location = new Point(this.Left - (mousePoint.X - e.X),
                    this.Top - (mousePoint.Y - e.Y));
            }
        }

        private void AirCommand_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y);
        }

        
    }
}
