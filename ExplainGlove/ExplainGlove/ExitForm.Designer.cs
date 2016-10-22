namespace ExplainGlove
{
    partial class ExitForm
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
            this.ExitBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.ExitBox)).BeginInit();
            this.SuspendLayout();
            // 
            // ExitBox
            // 
            this.ExitBox.BackColor = System.Drawing.Color.Gray;
            this.ExitBox.Location = new System.Drawing.Point(-8, -2);
            this.ExitBox.Name = "ExitBox";
            this.ExitBox.Size = new System.Drawing.Size(522, 324);
            this.ExitBox.TabIndex = 0;
            this.ExitBox.TabStop = false;
            this.ExitBox.Click += new System.EventHandler(this.ExitBox_Click);
            // 
            // ExitForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 310);
            this.Controls.Add(this.ExitBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "ExitForm";
            this.Text = "ExitForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.ExitBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox ExitBox;
    }
}