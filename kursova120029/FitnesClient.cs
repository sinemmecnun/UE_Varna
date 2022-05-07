using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kursova120029
{
    internal class FitnesClient
    {
        //private int nomerKlient;
        //private string imeKlient;
        //private int tipKlient;
        //public DateTime date;
        //private int duration;

        //public int NomerKlient
        //{
        //    get { return nomerKlient; }
        //    set 
        //    {
        //        if (value > 0)
        //        {
        //            nomerKlient = value;
        //        }
        //    }
        //}

        //public string ImeKlient
        //{
        //    set
        //    {
        //        if (value != string.Empty)
        //        {
        //            imeKlient = value;
        //        }
        //    }
        //    get { return imeKlient; }
        //}

        public int nomerKlient;
        public string imeKlient;
        public string tipKlient;
        //public DateTime date;
        public int duration;

        public FitnesClient(int number, string name, string tip, int prod)
        {
            nomerKlient = number;
            imeKlient = name;
            tipKlient = tip;
            //date = data;
            duration = prod;
        }

    }
}
