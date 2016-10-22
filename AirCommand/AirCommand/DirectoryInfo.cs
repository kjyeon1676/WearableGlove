using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirCommand
{
    class DirectoryInfo
    {
        struct FileInfo
        {
            public string itemName;
            public string itemExtension;
            public int calDate;
            public int calMinute;
        }
        public string sendStr;

        /// <summary>
        /// private Variable
        /// </summary>
        private int MinuteMin;
        private int Daymin;
        private int min_index = 0;
        private int infoIndex = 0;


        FileInfo [] info = new FileInfo[10];
        DateTime prevTime = new DateTime(0);
        public void FindCreationTime(string dirPath)
        {
            if (System.IO.Directory.Exists(dirPath))
            {
                System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(dirPath);
                string TarGetFolder = di.FullName;
                foreach(var item in di.GetFiles())
                {
                    string FileName = item.Name;
                    string FileType = item.Extension;
                    DateTime time1 = item.CreationTime;
                    DateTime time2 = DateTime.Now;
                    TimeSpan time3 = time2 - time1;
                    int time4 = time3.Days;
                    int time5 = time3.Minutes;
                    info[infoIndex].itemName = FileName;
                    info[infoIndex].itemExtension = FileType;
                    info[infoIndex].calMinute = time5;
                    info[infoIndex++].calDate = time4;
                }
                calMinTime();
                sendStr = info[min_index].itemName;
            }
        }
        public void calMinTime()
        {
            Daymin = 99999999;
            MinuteMin = 99999999;
            for(int i =0; i<infoIndex; i++)
            {
                if (info[i].calDate <= Daymin)
                {
                    if (Daymin == 0)
                    {
                        if (info[i].calMinute < MinuteMin)
                        {
                            MinuteMin = info[i].calMinute;
                            min_index = i;
                        }
                    }
                    else
                    {
                        Daymin = info[i].calDate;
                        min_index = i;
                    }
                }
            }
        }
    }
}
