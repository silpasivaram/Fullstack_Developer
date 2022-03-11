using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                MainSettings Setting = (MainSettings)Application["Settings"];

                if (Setting.RefreshCounter == 0)
                {
                    Setting.RefreshCounter = 1;
                    XmlSerial.SaveSettings(Setting);
                    Labeldisply.Text = Setting.Text1;
                }

                else
                {
                    Setting.RefreshCounter = 0;
                    XmlSerial.SaveSettings(Setting);
                    Labeldisply.Text = Setting.Text2;
                }

            }
            catch (Exception)
            {

            }
        }
    }
}