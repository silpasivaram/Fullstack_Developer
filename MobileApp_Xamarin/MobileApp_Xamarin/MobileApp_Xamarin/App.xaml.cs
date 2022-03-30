using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace MobileApp_Xamarin
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            Device.SetFlags(new[] { "Expander_Experimental" });
            MainPage = new NavigationPage(new MainPage())

            {
                BarBackgroundColor = Color.FromHex("#EFF1F5"),
            };
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
