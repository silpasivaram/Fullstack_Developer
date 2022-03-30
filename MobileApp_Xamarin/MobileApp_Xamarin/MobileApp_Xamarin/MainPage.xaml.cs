using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace MobileApp_Xamarin
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
            

        }

        private async void P_image_Click(object sender, EventArgs e)
        {

            await Navigation.PushAsync(new Policy_Page());


        }
    }
}
