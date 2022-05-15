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
        
        private void търсиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //opens a new dialog window where you can search by name and client number
            new Klient().ShowDialog();
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // declare variables
            int nomer = int.Parse(textBox1.Text);
            string ime = textBox2.Text;
            string tip = comboBox1.SelectedItem.ToString();
            // datetimepicker not incorporated
            int duration = int.Parse(textBox3.Text);

            // save in a file
            FileStream fileKlienti = new FileStream(FileName, FileMode.OpenOrCreate);
            fileKlienti.Seek(0, SeekOrigin.End);
            BinaryWriter bw = new BinaryWriter(fileKlienti);
            bw.Write(nomer);
            bw.Write(ime);
            bw.Write(tip);
            bw.Write(duration);
            fileKlienti.Close();
            MessageBox.Show("Данните бяха записани успешно."); 

            //clears the form
            textBox1.Text = String.Empty;
            textBox2.Text = String.Empty;
            textBox3.Text = String.Empty;
            comboBox1.Text = String.Empty;
        }

        private void пресметниToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Calculate().ShowDialog();
        }
    }
}
