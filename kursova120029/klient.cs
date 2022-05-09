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
                klienti.Add(klient);
            }
            fileKlienti.Close();
            if (number != -1)
            {
                textBox1.Text = number.ToString();
            }
            if (name != string.Empty)
            {
                textBox2.Text = name;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
            Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int nomer = int.Parse(textBox1.Text);
            string ime = textBox2.Text;
            int totalDuration = 0;
            foreach (FitnesClient klient in klienti)
            {
                if (klient.nomerKlient == nomer && klient.imeKlient == ime)
                {
                    totalDuration += klient.duration;
                    dataGridView1.Rows.Add(klient.nomerKlient, klient.imeKlient, klient.tipKlient, klient.duration);
                }
            }
            label1.Text = totalDuration.ToString();
        }
    }
}
