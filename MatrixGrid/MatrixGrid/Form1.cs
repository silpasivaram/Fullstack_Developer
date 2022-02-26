using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;


namespace MatrixGrid
{
    public partial class Form1 : Form
    {
        public int m_iOffset = 50;
        public const int m_iX = 50;
        public const int m_iY = 50;
        public static int m_iNoOfRows =0;
        public static int m_iNoOfCells=8;
        Thread m_Grid;
        public bool m_Boolstate = true;
        public Form1()
        {
            InitializeComponent();
            
        }



        private void toolStripButtonPlay_Click(object sender, EventArgs e)
        {
            m_Grid = null;
            m_Boolstate = true;
            m_Grid = new Thread(new ThreadStart(threadPgm));
            m_Grid.Start();
        }

        private void toolStripButtonPause_Click(object sender, EventArgs e)
        {
            m_Boolstate = false;
           
        }

        private void toolStripButtonStop_Click(object sender, EventArgs e)
        {
            m_Boolstate = false;
            m_iNoOfRows = 0;
            Invalidate();
        }

        private void toolStripMenuItem3X3_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 3;
            x4ToolStripMenuItem.Checked = false;
            x5ToolStripMenuItem.Checked = false;
            x6ToolStripMenuItem.Checked = false;
            x7ToolStripMenuItem.Checked = false;
            x8ToolStripMenuItem.Checked = false;
        }

        private void x4ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 4;
            toolStripMenuItem3X3.Checked = false;
            x5ToolStripMenuItem.Checked = false;
            x6ToolStripMenuItem.Checked = false;
            x7ToolStripMenuItem.Checked = false;
            x8ToolStripMenuItem.Checked = false;
        }

        private void x5ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 5;
            toolStripMenuItem3X3.Checked = false;
            x4ToolStripMenuItem.Checked = false;
            x6ToolStripMenuItem.Checked = false;
            x7ToolStripMenuItem.Checked = false;
            x8ToolStripMenuItem.Checked = false;
        }

        private void x6ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 6;
            toolStripMenuItem3X3.Checked = false;
            x4ToolStripMenuItem.Checked = false;
            x5ToolStripMenuItem.Checked = false;
            x7ToolStripMenuItem.Checked = false;
            x8ToolStripMenuItem.Checked = false;
        }

        private void x7ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 7;
            toolStripMenuItem3X3.Checked = false;
            x4ToolStripMenuItem.Checked = false;
            x5ToolStripMenuItem.Checked = false; 
            x6ToolStripMenuItem.Checked = false;
            x8ToolStripMenuItem.Checked = false;
        }

        private void x8ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_iNoOfCells = 8;
            toolStripMenuItem3X3.Checked = false;
            x4ToolStripMenuItem.Checked = false;
            x5ToolStripMenuItem.Checked = false;
            x6ToolStripMenuItem.Checked = false;
            x7ToolStripMenuItem.Checked = false;
           

        }
        void threadPgm()
        {
            int dx = 1;
            while(m_Boolstate)
            {

                m_iNoOfRows += dx;
                if (m_iNoOfRows >= m_iNoOfCells)
                    dx = -1;
                if (m_iNoOfRows <= 1)
                    dx = 1;
                this.Invalidate();
                Thread.Sleep(500);
            }
           
            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics boardLayout = this.CreateGraphics();
            Pen layout = new Pen(Color.LightSeaGreen);
            layout.Width = 5;
            int X = m_iX;
            int Y = m_iY;

            for (int i = 0; i <= m_iNoOfRows; i++)
            {
                boardLayout.DrawLine(layout, m_iX, Y, m_iX + this.m_iOffset * m_iNoOfRows, Y);
                Y += m_iOffset;

            }
            for (int j = 0; j <= m_iNoOfRows; j++)
            {
                boardLayout.DrawLine(layout, X, m_iX, X, m_iX + this.m_iOffset * m_iNoOfRows);
                X += m_iOffset;

            }
        }

        
    }
}
