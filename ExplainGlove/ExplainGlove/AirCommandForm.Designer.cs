namespace ExplainGlove
{
    partial class AirCommandForm
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
            this.AirCommandBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.AirCommandBox)).BeginInit();
            this.SuspendLayout();
            // 
            // AirCommandBox
            // 
            this.AirCommandBox.BackColor = System.Drawing.Color.Gray;
            this.AirCommandBox.Location = new System.Drawing.Point(-6, -3);
            this.AirCommandBox.Name = "AirCommandBox";
            this.AirCommandBox.Size = new System.Drawing.Size(517, 329);
            this.AirCommandBox.TabIndex = 0;
            this.AirCommandBox.TabStop = false;
            this.AirCommandBox.Click += new System.EventHandler(this.AirCommandBox_Click);
            // 
            // AirCommandForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 320);
            this.Controls.Add(this.AirCommandBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "AirCommandForm";
            this.Text = "AirCommandForm";
            this.TransparencyKey = System.Drawing.Color.Gray;
            ((System.ComponentModel.ISupportInitialize)(this.AirCommandBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox AirCommandBox;
    }
}