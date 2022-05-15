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
    public partial class Calculate : Form
    {
        public Calculate()
        {
            InitializeComponent();
        }
        int totalDuration = 0, numberOfClients = 0;
        string FileName = "klienti.dat";
        private void добавиКлиентToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
            Close();
        }

        private void търсенеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Klient().ShowDialog();
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //declare and read type and price
            string searchType = comboBox1.SelectedItem.ToString();
            int price;
            int.TryParse(textBox1.Text, out price);
            if (price == 0)
            {
                MessageBox.Show("Invalid price");
                int.TryParse(textBox1.Text, out price);
            }

            //search for type of client in the file
            Read(searchType);


            if (searchType == "без карта")
            {
                //печалбата се изчислява за общ брой часове
                //if totalDuration < 60 result is 0
                int result = (int)totalDuration / 60;
                result *= price;
                label4.Text = result.ToString();
            }
            else
            {
                int result = numberOfClients * price;
                label4.Text = result.ToString();
            }

            //clear
            numberOfClients = 0;
            totalDuration = 0;

        }

        private void Read(string typeClient)
        {
            ArrayList nomera = new ArrayList();
            //reads data from the file
            FileStream fileKlienti = new FileStream(FileName, FileMode.Open);
            BinaryReader br = new BinaryReader(fileKlienti);
            while (fileKlienti.Position < fileKlienti.Length)
            {
                int number = br.ReadInt32();
                string name = br.ReadString();
                string type = br.ReadString();
                int duration = br.ReadInt32();
                if (type == typeClient)
                {
                    if (type != "без карта" && !nomera.Contains(number))
                    {
                        nomera.Add(number);
                        numberOfClients++;
                    }
                    totalDuration += duration;
                }
            }
            fileKlienti.Close();
        }
    }
}
