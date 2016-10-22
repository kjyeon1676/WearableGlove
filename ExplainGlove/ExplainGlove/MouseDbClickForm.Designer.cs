namespace ExplainGlove
{
    partial class MouseDbClickForm
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
            this.MouseDbClickBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.MouseDbClickBox)).BeginInit();
            this.SuspendLayout();
            // 
            // MouseDbClickBox
            // 
            this.MouseDbClickBox.BackColor = System.Drawing.Color.Gray;
            this.MouseDbClickBox.Location = new System.Drawing.Point(-2, 0);
            this.MouseDbClickBox.Name = "MouseDbClickBox";
            this.MouseDbClickBox.Size = new System.Drawing.Size(590, 363);
            this.MouseDbClickBox.TabIndex = 0;
            this.MouseDbClickBox.TabStop = false;
            this.MouseDbClickBox.Click += new System.EventHandler(this.MouseDbClickBox_Click);
            // 
            // MouseDbClickForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(560, 340);
            this.Controls.Add(this.MouseDbClickBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MouseDbClickForm";
            this.Text = "MouseDbClickForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.MouseDbClickBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox MouseDbClickBox;
    }
}