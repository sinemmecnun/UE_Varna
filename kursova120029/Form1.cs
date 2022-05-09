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

        string FileName = "klienti.dat";
        //Dictionary<string, int> tipKlient = new Dictionary<string, int>()
        //{
        //    {"без карта", 1},
        //    {"с карта за месец", 2},
        //    {"с карта за брой посещения", 3 }
        //};

        private void търсиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Klient().ShowDialog();
            Close();
        }

        private void пресметниToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Calculate().ShowDialog();
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // declare variables
            int nomer = int.Parse(textBox1.Text);
            string ime = textBox2.Text;
            string tip = comboBox1.SelectedItem.ToString();
            // add datetime !!
            int duration = int.Parse(textBox3.Text);

            // save in a file
            //deletes everything
            FileStream fileKlienti = new FileStream(FileName, FileMode.OpenOrCreate);
            BinaryWriter bw = new BinaryWriter(fileKlienti);
            bw.Write(nomer);
            bw.Write(ime);
            bw.Write(tip);
            bw.Write(duration);
            fileKlienti.Close();
            MessageBox.Show("Данните бяха записани успешно.");
 
            new Klient().ShowDialog();
            Close();
        }
    }
}
