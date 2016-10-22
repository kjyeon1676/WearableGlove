namespace ExplainGlove
{
    partial class MouseWheelForm
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
            this.MouseWheelBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.MouseWheelBox)).BeginInit();
            this.SuspendLayout();
            // 
            // MouseWheelBox
            // 
            this.MouseWheelBox.BackColor = System.Drawing.Color.Gray;
            this.MouseWheelBox.Location = new System.Drawing.Point(-2, -2);
            this.MouseWheelBox.Name = "MouseWheelBox";
            this.MouseWheelBox.Size = new System.Drawing.Size(580, 357);
            this.MouseWheelBox.TabIndex = 0;
            this.MouseWheelBox.TabStop = false;
            this.MouseWheelBox.Click += new System.EventHandler(this.MouseWheelBox_Click);
            // 
            // MouseWheelForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(560, 340);
            this.Controls.Add(this.MouseWheelBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MouseWheelForm";
            this.Text = "MouseWheelForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.MouseWheelBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox MouseWheelBox;
    }
}