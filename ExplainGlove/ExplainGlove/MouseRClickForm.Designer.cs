namespace ExplainGlove
{
    partial class MouseRClickForm
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
            this.MouseRClickBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.MouseRClickBox)).BeginInit();
            this.SuspendLayout();
            // 
            // MouseRClickBox
            // 
            this.MouseRClickBox.BackColor = System.Drawing.Color.Gray;
            this.MouseRClickBox.Location = new System.Drawing.Point(-1, -2);
            this.MouseRClickBox.Name = "MouseRClickBox";
            this.MouseRClickBox.Size = new System.Drawing.Size(355, 340);
            this.MouseRClickBox.TabIndex = 0;
            this.MouseRClickBox.TabStop = false;
            this.MouseRClickBox.Click += new System.EventHandler(this.MouseRClickBox_Click);
            // 
            // MouseRClickForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(350, 332);
            this.Controls.Add(this.MouseRClickBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MouseRClickForm";
            this.Text = "MouseRClickForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.MouseRClickBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox MouseRClickBox;
    }
}