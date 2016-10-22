using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace AirCommand
{
    class FileExecuter
    {
        public void runExcutableFile(string exePath)
        {
            System.Diagnostics.Process.Start(exePath);
        }
    }

}
