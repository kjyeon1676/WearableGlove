namespace AirCommand
{
    partial class MainFrame
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainFrame));
            this.AirCommand = new DevComponents.DotNetBar.RadialMenu();
            this.radialMenuItem1 = new DevComponents.DotNetBar.RadialMenuItem();
            this.SuspendLayout();
            // 
            // AirCommand
            // 
            this.AirCommand.BackColor = System.Drawing.Color.Transparent;
            this.AirCommand.Items.AddRange(new DevComponents.DotNetBar.BaseItem[] {
            this.radialMenuItem1});
            this.AirCommand.Location = new System.Drawing.Point(119, 106);
            this.AirCommand.Name = "AirCommand";
            this.AirCommand.Size = new System.Drawing.Size(56, 56);
            this.AirCommand.Symbol = "";
            this.AirCommand.SymbolSize = 20F;
            this.AirCommand.TabIndex = 0;
            this.AirCommand.Text = "radialMenu1";
            this.AirCommand.ItemClick += new System.EventHandler(this.AirCommand_ItemClick);
            this.AirCommand.MouseDown += new System.Windows.Forms.MouseEventHandler(this.AirCommand_MouseDown);
            this.AirCommand.MouseMove += new System.Windows.Forms.MouseEventHandler(this.AirCommand_MouseMove);
            // 
            // radialMenuItem1
            // 
            this.radialMenuItem1.CircularBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.radialMenuItem1.CircularBorderColor = System.Drawing.Color.Red;
            this.radialMenuItem1.CircularForeColor = System.Drawing.Color.Red;
            this.radialMenuItem1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.radialMenuItem1.Description = "AirCommand Exit";
            this.radialMenuItem1.Name = "radialMenuItem1";
            this.radialMenuItem1.Symbol = "";
            this.radialMenuItem1.Text = "Exit";
            // 
            // MainFrame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.ControlBox = false;
            this.Controls.Add(this.AirCommand);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainFrame";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AirCommand";
            this.TransparencyKey = System.Drawing.SystemColors.Control;
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.RadialMenu AirCommand;
        private DevComponents.DotNetBar.RadialMenuItem radialMenuItem1;

    }
}

