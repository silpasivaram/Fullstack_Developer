using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Simple_Interest
{
    public partial class MainPage : ContentPage
    {
        public float m_Principal;

        public float m_Interest;

        public int m_Years;
        public MainPage()
        {
            InitializeComponent();
            m_Principal = 0;
            m_Interest = 0;
            m_Years = 0;
        }

        private void Button_Clicked(object sender, EventArgs e)
        {
            try
            {
                m_Principal = float.Parse(Pamt.Text);

                m_Interest = float.Parse(Rate.Text);

                m_Years = int.Parse(Years.Text);

                var result = m_Principal * m_Years * m_Interest / 100;

                var result1 = result + m_Principal;

                Iamt.Text = result.ToString();

                Tamt.Text = result1.ToString();

            }
            catch(Exception)
            {
                Msg.Text = "Please Enter All Fields";
            }

        }

        private void Button_Clicked_1(object sender, EventArgs e)
        {
            Pamt.Text = "";

            Rate.Text = "";

            Years.Text = "";

            Iamt.Text = "";

            Tamt.Text = "";

            Msg.Text = "";

        }
    }
}
