using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace kursova120029
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        ArrayList klienti = new ArrayList();
        string FileName = "klienti.dat";
        //Dictionary<string, int> tipKlient = new Dictionary<string, int>()
        //{
        //    {"без карта", 1},
        //    {"с карта за месец", 2},
        //    {"с карта за брой посещения", 3 }
        //};
        private void button1_Click(object sender, EventArgs e)
        {
            int nomer = int.Parse(textBox1.Text);
            string ime = textBox2.Text;
            string tip = comboBox1.SelectedItem.ToString();
            // datetime
            int duration = int.Parse(textBox3.Text);
            FitnesClient klient = new FitnesClient(nomer, ime, tip, duration);
            klienti.Add(klient);
            MessageBox.Show("Данните бяха записани успешно.");

            //if (!File.Exists(FileName))
            //{
            //    FileStream file = new FileStream(FileName, FileMode.CreateNew);
            //}
            // zapis vuv fayl
            new klient().ShowDialog();
            Close();
        }

        private void търсиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new klient().ShowDialog();
            Close();
        }
    }
}
