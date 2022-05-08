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

namespace kursova120029
{
    public partial class klient : Form
    {
        public klient()
        {
            InitializeComponent();
        }
        ArrayList klienti = new ArrayList();
        private void button2_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
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
            listBox3.Items.Add(totalDuration);
        }

    }
}
