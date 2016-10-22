namespace ExplainGlove
{
    partial class WindowKeyForm
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
            this.WindowKeyBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.WindowKeyBox)).BeginInit();
            this.SuspendLayout();
            // 
            // WindowKeyBox
            // 
            this.WindowKeyBox.BackColor = System.Drawing.Color.Gray;
            this.WindowKeyBox.Location = new System.Drawing.Point(-2, -3);
            this.WindowKeyBox.Name = "WindowKeyBox";
            this.WindowKeyBox.Size = new System.Drawing.Size(383, 371);
            this.WindowKeyBox.TabIndex = 0;
            this.WindowKeyBox.TabStop = false;
            this.WindowKeyBox.Click += new System.EventHandler(this.WindowKeyBox_Click);
            // 
            // WindowKeyForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(368, 357);
            this.Controls.Add(this.WindowKeyBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "WindowKeyForm";
            this.Text = "WindowKeyForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.WindowKeyBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox WindowKeyBox;
    }
}