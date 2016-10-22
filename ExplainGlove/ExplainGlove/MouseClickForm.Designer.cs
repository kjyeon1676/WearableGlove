namespace ExplainGlove
{
    partial class MouseClickForm
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
            this.MouseClickBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.MouseClickBox)).BeginInit();
            this.SuspendLayout();
            // 
            // MouseClickBox
            // 
            this.MouseClickBox.BackColor = System.Drawing.Color.Gray;
            this.MouseClickBox.Location = new System.Drawing.Point(0, -2);
            this.MouseClickBox.Name = "MouseClickBox";
            this.MouseClickBox.Size = new System.Drawing.Size(573, 345);
            this.MouseClickBox.TabIndex = 0;
            this.MouseClickBox.TabStop = false;
            this.MouseClickBox.Click += new System.EventHandler(this.MouseClickBox_Click);
            // 
            // MouseClickForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(560, 340);
            this.Controls.Add(this.MouseClickBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MouseClickForm";
            this.Text = "MouseClickForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.MouseClickBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox MouseClickBox;
    }
}