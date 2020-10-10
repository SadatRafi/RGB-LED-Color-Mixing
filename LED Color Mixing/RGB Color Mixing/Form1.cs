using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace RGB_Color_Mixing
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string Data = trackBar1.Value.ToString() + trackBar2.Value.ToString() + trackBar3.Value.ToString();
            try
            {
                serialPort1.Open();
                serialPort1.Write(Data);
                serialPort1.Close();
            }
            catch
            {
                MessageBox.Show("COM3 Not Available");
            }
            
        }
    }
}
