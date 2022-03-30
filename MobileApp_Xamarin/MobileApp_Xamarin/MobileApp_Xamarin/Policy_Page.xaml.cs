using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace MobileApp_Xamarin
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Policy_Page : ContentPage
    {
        public Policy_Page()
        {
            InitializeComponent();
            NavigationPage.SetIconColor(this, Color.FromHex("#000000"));
           
        }

       

        private void ListView_ItemTapped(object sender, ItemTappedEventArgs e)
        {
            var product = e.Item as Policies;
            var vm = BindingContext as ListView;
            vm?.ShowOrHidePoducts(product);
        }


        private void ExpanderActivePolicy_Tapped(object sender, EventArgs e)
        {
            if (ExpanderActivePolicy.IsExpanded != false)
            {
                ExpanderActivePolicy.IsExpanded = true;
                ImgActivePolicyUpdown.Source = ImageSource.FromFile("chevron_up.png");

               
            }
            else
            {
                ExpanderActivePolicy.IsExpanded = false;
                ImgActivePolicyUpdown.Source = ImageSource.FromFile("chevron_down.png");
            }
        }

        

    }
}