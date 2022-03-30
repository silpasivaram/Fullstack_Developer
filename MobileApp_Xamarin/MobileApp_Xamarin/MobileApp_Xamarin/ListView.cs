using System;
using System.Collections.Generic;
using System.Text;
using System.Collections.ObjectModel;
namespace MobileApp_Xamarin
{
    public class ListView
    {
        private Policies _oldPolicies;
        public ObservableCollection<Policies> Policies { get; set; }
        public ListView()
        {
            Policies = new ObservableCollection<Policies>
            {
                new Policies
                {
                    Title="Active Policy",
                    SubItem1="View Policy List",
                    SubItem2="Download Policy Schedule",
                    SubItem3 ="View Premium Receipt", 
                    SubItem4 ="View Product Benefits", 
                    SubItem5 ="Surrendering Polices",
                    SubItem6 ="Mail Me Policy",
                    IsVisible = false,
                },
                new Policies
                {
                 Title="Policy Changes",
                  IsVisible = false,
               },

                 new Policies
               {
                Title="Payments",
                IsVisible = false,
                }

            };
        }
        public void ShowOrHidePoducts(Policies product)
        {
            if (_oldPolicies == product)
            {
                // click twice on the same item will hide it
                product.IsVisible = !product.IsVisible;
                UpdateProducts(product);
            }
            else
            {
                if (_oldPolicies != null)
                {
                    // hide previous selected item
                    _oldPolicies.IsVisible = false;
                    UpdateProducts(product);

                }
                // show selected item
                product.IsVisible = true;
                UpdateProducts(product);
            }

            _oldPolicies = product;
        }

        private void UpdateProducts(Policies policy)
        {
            var index = Policies.IndexOf(policy);
            Policies.Remove(policy);
            Policies.Insert(index, policy);
        }

    }
}

