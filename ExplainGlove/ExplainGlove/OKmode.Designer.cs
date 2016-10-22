namespace ExplainGlove
{
    partial class OKmode
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
            this.okModePicBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.okModePicBox)).BeginInit();
            this.SuspendLayout();
            // 
            // okModePicBox
            // 
            this.okModePicBox.BackColor = System.Drawing.Color.Gray;
            this.okModePicBox.Location = new System.Drawing.Point(-6, -5);
            this.okModePicBox.Name = "okModePicBox";
            this.okModePicBox.Size = new System.Drawing.Size(536, 309);
            this.okModePicBox.TabIndex = 0;
            this.okModePicBox.TabStop = false;
            this.okModePicBox.Click += new System.EventHandler(this.okModePicBox_Click);
            // 
            // OKmode
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(516, 300);
            this.Controls.Add(this.okModePicBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "OKmode";
            this.Text = "OKmode";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.okModePicBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox okModePicBox;
    }
}