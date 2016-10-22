namespace ExplainGlove
{
    partial class KeybdAltEscForm
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
            this.KeybdAltEscBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltEscBox)).BeginInit();
            this.SuspendLayout();
            // 
            // KeybdAltEscBox
            // 
            this.KeybdAltEscBox.BackColor = System.Drawing.Color.Gray;
            this.KeybdAltEscBox.Location = new System.Drawing.Point(-2, -2);
            this.KeybdAltEscBox.Name = "KeybdAltEscBox";
            this.KeybdAltEscBox.Size = new System.Drawing.Size(585, 355);
            this.KeybdAltEscBox.TabIndex = 0;
            this.KeybdAltEscBox.TabStop = false;
            this.KeybdAltEscBox.Click += new System.EventHandler(this.KeybdAltEscBox_Click);
            // 
            // KeybdAltEscForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(466, 315);
            this.Controls.Add(this.KeybdAltEscBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "KeybdAltEscForm";
            this.Text = "KeybdAltEscForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.KeybdAltEscBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox KeybdAltEscBox;
    }
}