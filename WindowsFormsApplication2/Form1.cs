using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        long timp=0;
        int ceva;
       // int cicluri = 0;

        int[] elevi = { 1, 6, 4, 12, 32, 14 }; 
        public Form1()
        {
            InitializeComponent();
        }

        public void TimerTick(object sender, EventArgs e)
        {
            Random r = new Random();
            double valY = r.NextDouble() * 8;
            chart1.Series["habar n-am"].Points.AddXY(chart1.Series["habar n-am"].Points.Count, timp);
            timp += timer1.Interval;

           // MessageBox.Show("Salut!");

          //  cicluri++;


           // if (cicluri >= 10)
             //   timer1.Stop();

           /* if (timer1.Interval > 100)
            {
                timer1.Interval -= 100;
            }
            else
            {
                timer1.Stop();
            }
            */

        }

        private void chart1_Click(object sender, EventArgs e)
        {
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //timer1.Interval = 1500;
            
            chart1.Series.Add("Clase");
            chart1.Series["Clase"].Enabled = true;
            for (int i = 0; i < elevi.Length; i++)
            {
                chart1.Series["Clase"].Points.AddXY(i, elevi[i]); //x = y, x e i-ul, y e val din cls elevi
            } 
            
            chart1.Series.Add("habar n-am");
            timer1.Tick += new EventHandler(TimerTick);
            timer1.Start();

        }

        private void trackBar1_MouseUp(object sender, MouseEventArgs e)
        {
           
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            timer1.Stop();
            timer1.Interval = trackBar1.Value;
            timer1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1.ShowDialog();
            string path = folderBrowserDialog1.SelectedPath;
            MessageBox.Show(path);
        }

        private void folderBrowserDialog1_HelpRequest(object sender, EventArgs e)
        {
            
        }

        private void salutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Salut!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
           // chart1.Show(
        }
       

       /* private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {

            Form1 f = new Form1();
            Form1 g = new Form1();
            f.Focus();
            g.Focus();
            f.Show();
            g.Show();
        }
        */

    }
}
