namespace ExplainGlove
{
    partial class Form1
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
            this.FirstMeuText = new System.Windows.Forms.Label();
            this.startGroupBox = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.basicGroupBox = new System.Windows.Forms.GroupBox();
            this.MouseDbClickText = new System.Windows.Forms.Label();
            this.MouseWheelText = new System.Windows.Forms.Label();
            this.MouseRClickText = new System.Windows.Forms.Label();
            this.MouseClickText = new System.Windows.Forms.Label();
            this.keybdGroupBox = new System.Windows.Forms.GroupBox();
            this.KeybdAltTabText = new System.Windows.Forms.Label();
            this.KeybdAltEscText = new System.Windows.Forms.Label();
            this.KeybdAltF4Text = new System.Windows.Forms.Label();
            this.etcGroupBox = new System.Windows.Forms.GroupBox();
            this.ExitText = new System.Windows.Forms.Label();
            this.WinTabSideModeText = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.NextPageBtn1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.OKModeText = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.startGroupBox.SuspendLayout();
            this.basicGroupBox.SuspendLayout();
            this.keybdGroupBox.SuspendLayout();
            this.etcGroupBox.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // FirstMeuText
            // 
            this.FirstMeuText.AutoSize = true;
            this.FirstMeuText.Location = new System.Drawing.Point(13, 13);
            this.FirstMeuText.Name = "FirstMeuText";
            this.FirstMeuText.Size = new System.Drawing.Size(396, 12);
            this.FirstMeuText.TabIndex = 0;
            this.FirstMeuText.Text = "환영합니다! MagicGlove입니다. 아래의 설명서를 잘 읽고 활용해주세요!";
            // 
            // startGroupBox
            // 
            this.startGroupBox.Controls.Add(this.label5);
            this.startGroupBox.Controls.Add(this.label4);
            this.startGroupBox.Controls.Add(this.label3);
            this.startGroupBox.Controls.Add(this.label2);
            this.startGroupBox.Location = new System.Drawing.Point(15, 38);
            this.startGroupBox.Name = "startGroupBox";
            this.startGroupBox.Size = new System.Drawing.Size(200, 112);
            this.startGroupBox.TabIndex = 1;
            this.startGroupBox.TabStop = false;
            this.startGroupBox.Text = "시작순서";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(7, 85);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(147, 12);
            this.label5.TabIndex = 3;
            this.label5.Text = "4. 원하는 손동작을 취한다";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label4.Location = new System.Drawing.Point(7, 63);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(171, 12);
            this.label4.TabIndex = 2;
            this.label4.Text = "3. 손을 주먹모양으로 움켜쥔다";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            this.label4.MouseLeave += new System.EventHandler(this.label4_MouseLeave);
            this.label4.MouseMove += new System.Windows.Forms.MouseEventHandler(this.label4_MouseMove);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 43);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(119, 12);
            this.label3.TabIndex = 1;
            this.label3.Text = "2. 제어시작을 누른다";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(83, 12);
            this.label2.TabIndex = 0;
            this.label2.Text = "1. 장갑을 낀다";
            // 
            // basicGroupBox
            // 
            this.basicGroupBox.Controls.Add(this.MouseDbClickText);
            this.basicGroupBox.Controls.Add(this.MouseWheelText);
            this.basicGroupBox.Controls.Add(this.MouseRClickText);
            this.basicGroupBox.Controls.Add(this.MouseClickText);
            this.basicGroupBox.Location = new System.Drawing.Point(221, 38);
            this.basicGroupBox.Name = "basicGroupBox";
            this.basicGroupBox.Size = new System.Drawing.Size(257, 112);
            this.basicGroupBox.TabIndex = 2;
            this.basicGroupBox.TabStop = false;
            this.basicGroupBox.Text = "Normal Mode";
            // 
            // MouseDbClickText
            // 
            this.MouseDbClickText.AutoSize = true;
            this.MouseDbClickText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.MouseDbClickText.Location = new System.Drawing.Point(6, 84);
            this.MouseDbClickText.Name = "MouseDbClickText";
            this.MouseDbClickText.Size = new System.Drawing.Size(199, 12);
            this.MouseDbClickText.TabIndex = 7;
            this.MouseDbClickText.Text = "더블클릭 : 검지손가락->중지손가락";
            this.MouseDbClickText.Click += new System.EventHandler(this.MouseDbClickText_Click);
            this.MouseDbClickText.MouseLeave += new System.EventHandler(this.MouseDbClickText_MouseLeave);
            this.MouseDbClickText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MouseDbClickText_MouseMove);
            // 
            // MouseWheelText
            // 
            this.MouseWheelText.AutoSize = true;
            this.MouseWheelText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.MouseWheelText.Location = new System.Drawing.Point(6, 61);
            this.MouseWheelText.Name = "MouseWheelText";
            this.MouseWheelText.Size = new System.Drawing.Size(233, 12);
            this.MouseWheelText.TabIndex = 6;
            this.MouseWheelText.Text = "마우스휠 : 엄지와 새끼손가락 제외 구부림";
            this.MouseWheelText.Click += new System.EventHandler(this.MouseWheelText_Click);
            this.MouseWheelText.MouseLeave += new System.EventHandler(this.MouseWheelText_MouseLeave);
            this.MouseWheelText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MouseWheelText_MouseMove);
            // 
            // MouseRClickText
            // 
            this.MouseRClickText.AutoSize = true;
            this.MouseRClickText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.MouseRClickText.Location = new System.Drawing.Point(6, 39);
            this.MouseRClickText.Name = "MouseRClickText";
            this.MouseRClickText.Size = new System.Drawing.Size(153, 12);
            this.MouseRClickText.TabIndex = 5;
            this.MouseRClickText.Text = "마우스우클릭 : 중지 구부림";
            this.MouseRClickText.Click += new System.EventHandler(this.MouseRClickText_Click);
            this.MouseRClickText.MouseLeave += new System.EventHandler(this.MouseRClickText_MouseLeave);
            this.MouseRClickText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MouseRClickText_MouseMove);
            // 
            // MouseClickText
            // 
            this.MouseClickText.AutoSize = true;
            this.MouseClickText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.MouseClickText.Location = new System.Drawing.Point(6, 17);
            this.MouseClickText.Name = "MouseClickText";
            this.MouseClickText.Size = new System.Drawing.Size(141, 12);
            this.MouseClickText.TabIndex = 4;
            this.MouseClickText.Text = "마우스클릭 : 검지 구부림";
            this.MouseClickText.Click += new System.EventHandler(this.MouseClickText_Click);
            this.MouseClickText.MouseLeave += new System.EventHandler(this.MouseClickText_MouseLeave);
            this.MouseClickText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MouseClickText_MouseMove);
            // 
            // keybdGroupBox
            // 
            this.keybdGroupBox.Controls.Add(this.KeybdAltTabText);
            this.keybdGroupBox.Controls.Add(this.KeybdAltEscText);
            this.keybdGroupBox.Controls.Add(this.KeybdAltF4Text);
            this.keybdGroupBox.Location = new System.Drawing.Point(15, 157);
            this.keybdGroupBox.Name = "keybdGroupBox";
            this.keybdGroupBox.Size = new System.Drawing.Size(221, 105);
            this.keybdGroupBox.TabIndex = 3;
            this.keybdGroupBox.TabStop = false;
            this.keybdGroupBox.Text = "Inverse Mode";
            // 
            // KeybdAltTabText
            // 
            this.KeybdAltTabText.AutoSize = true;
            this.KeybdAltTabText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.KeybdAltTabText.Location = new System.Drawing.Point(7, 75);
            this.KeybdAltTabText.Name = "KeybdAltTabText";
            this.KeybdAltTabText.Size = new System.Drawing.Size(174, 12);
            this.KeybdAltTabText.TabIndex = 10;
            this.KeybdAltTabText.Text = "Alt + F4 : 손가락 링모양 만들기";
            this.KeybdAltTabText.Click += new System.EventHandler(this.KeybdAltTabText_Click);
            this.KeybdAltTabText.MouseLeave += new System.EventHandler(this.KeybdAltTabText_MouseLeave);
            this.KeybdAltTabText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.KeybdAltTabText_MouseMove);
            // 
            // KeybdAltEscText
            // 
            this.KeybdAltEscText.AutoSize = true;
            this.KeybdAltEscText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.KeybdAltEscText.Location = new System.Drawing.Point(7, 48);
            this.KeybdAltEscText.Name = "KeybdAltEscText";
            this.KeybdAltEscText.Size = new System.Drawing.Size(205, 12);
            this.KeybdAltEscText.TabIndex = 9;
            this.KeybdAltEscText.Text = "WindowKey + E : 약지손가락 구부림";
            this.KeybdAltEscText.Click += new System.EventHandler(this.KeybdAltEscText_Click);
            this.KeybdAltEscText.MouseLeave += new System.EventHandler(this.KeybdAltEscText_MouseLeave);
            this.KeybdAltEscText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.KeybdAltEscText_MouseMove);
            // 
            // KeybdAltF4Text
            // 
            this.KeybdAltF4Text.AutoSize = true;
            this.KeybdAltF4Text.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.KeybdAltF4Text.Location = new System.Drawing.Point(7, 20);
            this.KeybdAltF4Text.Name = "KeybdAltF4Text";
            this.KeybdAltF4Text.Size = new System.Drawing.Size(208, 12);
            this.KeybdAltF4Text.TabIndex = 8;
            this.KeybdAltF4Text.Text = "WindowKey + m : 중지손가락 구부림";
            this.KeybdAltF4Text.Click += new System.EventHandler(this.KeybdAltF4Text_Click);
            this.KeybdAltF4Text.MouseLeave += new System.EventHandler(this.KeybdAltF4Text_MouseLeave);
            this.KeybdAltF4Text.MouseMove += new System.Windows.Forms.MouseEventHandler(this.KeybdAltF4Text_MouseMove);
            // 
            // etcGroupBox
            // 
            this.etcGroupBox.Controls.Add(this.ExitText);
            this.etcGroupBox.Controls.Add(this.WinTabSideModeText);
            this.etcGroupBox.Location = new System.Drawing.Point(248, 158);
            this.etcGroupBox.Name = "etcGroupBox";
            this.etcGroupBox.Size = new System.Drawing.Size(230, 66);
            this.etcGroupBox.TabIndex = 4;
            this.etcGroupBox.TabStop = false;
            this.etcGroupBox.Text = "Side Mode";
            // 
            // ExitText
            // 
            this.ExitText.AutoSize = true;
            this.ExitText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.ExitText.Location = new System.Drawing.Point(6, 43);
            this.ExitText.Name = "ExitText";
            this.ExitText.Size = new System.Drawing.Size(191, 12);
            this.ExitText.TabIndex = 9;
            this.ExitText.Text = "AirCommand : 약지손가락 구부림";
            this.ExitText.Click += new System.EventHandler(this.ExitText_Click);
            this.ExitText.MouseLeave += new System.EventHandler(this.ExitText_MouseLeave);
            this.ExitText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ExitText_MouseMove);
            // 
            // WinTabSideModeText
            // 
            this.WinTabSideModeText.AutoSize = true;
            this.WinTabSideModeText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.WinTabSideModeText.Location = new System.Drawing.Point(6, 21);
            this.WinTabSideModeText.Name = "WinTabSideModeText";
            this.WinTabSideModeText.Size = new System.Drawing.Size(201, 12);
            this.WinTabSideModeText.TabIndex = 8;
            this.WinTabSideModeText.Text = "Win + Tab : 중지손가락 구부림 상태";
            this.WinTabSideModeText.Click += new System.EventHandler(this.AirCommandText_Click);
            this.WinTabSideModeText.MouseLeave += new System.EventHandler(this.AirCommandText_MouseLeave);
            this.WinTabSideModeText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.AirCommandText_MouseMove);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(277, 288);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(102, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "확인";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // NextPageBtn1
            // 
            this.NextPageBtn1.Location = new System.Drawing.Point(386, 286);
            this.NextPageBtn1.Name = "NextPageBtn1";
            this.NextPageBtn1.Size = new System.Drawing.Size(92, 23);
            this.NextPageBtn1.TabIndex = 6;
            this.NextPageBtn1.Text = "다음";
            this.NextPageBtn1.UseVisualStyleBackColor = true;
            this.NextPageBtn1.Click += new System.EventHandler(this.NextPageBtn1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.OKModeText);
            this.groupBox1.Location = new System.Drawing.Point(248, 232);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(230, 48);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ok Mode";
            // 
            // OKModeText
            // 
            this.OKModeText.AutoSize = true;
            this.OKModeText.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.OKModeText.Location = new System.Drawing.Point(8, 13);
            this.OKModeText.Name = "OKModeText";
            this.OKModeText.Size = new System.Drawing.Size(171, 12);
            this.OKModeText.TabIndex = 0;
            this.OKModeText.Text = "← + → : 손가락 링모양 만들기";
            this.OKModeText.Click += new System.EventHandler(this.OKModeText_Click);
            this.OKModeText.MouseLeave += new System.EventHandler(this.OKModeText_MouseLeave);
            this.OKModeText.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OKModeText_MouseMove);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "감도조절 : ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::ExplainGlove.Properties.Resources.startimage;
            this.ClientSize = new System.Drawing.Size(493, 317);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.NextPageBtn1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.etcGroupBox);
            this.Controls.Add(this.keybdGroupBox);
            this.Controls.Add(this.basicGroupBox);
            this.Controls.Add(this.startGroupBox);
            this.Controls.Add(this.FirstMeuText);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "설명서";
            this.DoubleClick += new System.EventHandler(this.Form1_DoubleClick);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.startGroupBox.ResumeLayout(false);
            this.startGroupBox.PerformLayout();
            this.basicGroupBox.ResumeLayout(false);
            this.basicGroupBox.PerformLayout();
            this.keybdGroupBox.ResumeLayout(false);
            this.keybdGroupBox.PerformLayout();
            this.etcGroupBox.ResumeLayout(false);
            this.etcGroupBox.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label FirstMeuText;
        private System.Windows.Forms.GroupBox startGroupBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox basicGroupBox;
        private System.Windows.Forms.Label MouseDbClickText;
        private System.Windows.Forms.Label MouseWheelText;
        private System.Windows.Forms.Label MouseRClickText;
        private System.Windows.Forms.Label MouseClickText;
        private System.Windows.Forms.GroupBox keybdGroupBox;
        private System.Windows.Forms.Label KeybdAltTabText;
        private System.Windows.Forms.Label KeybdAltEscText;
        private System.Windows.Forms.Label KeybdAltF4Text;
        private System.Windows.Forms.GroupBox etcGroupBox;
        private System.Windows.Forms.Label ExitText;
        private System.Windows.Forms.Label WinTabSideModeText;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button NextPageBtn1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label OKModeText;
        private System.Windows.Forms.Label label1;
    }
}

