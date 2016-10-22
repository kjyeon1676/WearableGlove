namespace ExplainGlove
{
    partial class KeybdAltTabForm
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
            this.KeybdAltTabBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltTabBox)).BeginInit();
            this.SuspendLayout();
            // 
            // KeybdAltTabBox
            // 
            this.KeybdAltTabBox.BackColor = System.Drawing.Color.Gray;
            this.KeybdAltTabBox.Location = new System.Drawing.Point(-2, -2);
            this.KeybdAltTabBox.Name = "KeybdAltTabBox";
            this.KeybdAltTabBox.Size = new System.Drawing.Size(504, 379);
            this.KeybdAltTabBox.TabIndex = 0;
            this.KeybdAltTabBox.TabStop = false;
            this.KeybdAltTabBox.Click += new System.EventHandler(this.KeybdAltTabBox_Click);
            // 
            // KeybdAltTabForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(481, 319);
            this.Controls.Add(this.KeybdAltTabBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "KeybdAltTabForm";
            this.Text = "KeybdAltTabForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltTabBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox KeybdAltTabBox;
    }
}