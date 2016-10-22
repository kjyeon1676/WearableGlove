namespace ExplainGlove
{
    partial class KeybdWinKeyEForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.KeybdAltF4Box = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltF4Box)).BeginInit();
            this.SuspendLayout();
            // 
            // KeybdAltF4Box
            // 
            this.KeybdAltF4Box.BackColor = System.Drawing.Color.Gray;
            this.KeybdAltF4Box.Location = new System.Drawing.Point(-2, -1);
            this.KeybdAltF4Box.Name = "KeybdAltF4Box";
            this.KeybdAltF4Box.Size = new System.Drawing.Size(585, 373);
            this.KeybdAltF4Box.TabIndex = 0;
            this.KeybdAltF4Box.TabStop = false;
            this.KeybdAltF4Box.Click += new System.EventHandler(this.KeybdAltF4Box_Click);
            // 
            // KeybdWinKeyEForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(469, 311);
            this.Controls.Add(this.KeybdAltF4Box);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "KeybdWinKeyEForm";
            this.Text = "KeybdAltF4Form";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltF4Box)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox KeybdAltF4Box;
    }
}