using System;
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

        private void button2_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
