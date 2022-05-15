using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Collections;

namespace kursova120029
{
    public partial class Klient : Form
    {
        public Klient()
        {
            InitializeComponent();
        }

        ArrayList klienti = new ArrayList();
        string FileName = "klienti.dat";
        private void Klient_Load(object sender, EventArgs e)
        {
            //reads from the file and loads the data to datagridview
            FileStream fileKlienti = new FileStream(FileName, FileMode.OpenOrCreate);
            BinaryReader br = new BinaryReader(fileKlienti);
            int number = -1;
            string name = string.Empty;

            while (fileKlienti.Position < fileKlienti.Length)
            {
                number = br.ReadInt32();
                name = br.ReadString();
                string type = br.ReadString();
                int duration = br.ReadInt32();
                FitnesClient klient = new FitnesClient(number, name, type, duration);
                dataGridView1.Rows.Add(number, name, type, duration);
                klienti.Add(klient);
            }
            fileKlienti.Close();

            //finds the last added client
            if (number != -1)
            {
                textBox1.Text = number.ToString();
            }
            if (name != string.Empty)
            {
                textBox2.Text = name;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //reads the data for the client we want to search for
            int nomer = int.Parse(textBox1.Text);
            string ime = textBox2.Text;
            int totalDuration = 0;

            //finds the client's logs and calculates the total duration of their visits
            dataGridView1.Rows.Clear();
            foreach (FitnesClient klient in klienti)
            {
                if (klient.nomerKlient == nomer && klient.imeKlient == ime)
                {
                    totalDuration += klient.duration;
                    dataGridView1.Rows.Add(klient.nomerKlient, klient.imeKlient, klient.tipKlient, klient.duration);
                }
            }
            label3.Text = totalDuration.ToString();
        }

        private void добавиКлиентToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
        }

        private void пресметниToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Calculate().ShowDialog();
        }
    }
}
