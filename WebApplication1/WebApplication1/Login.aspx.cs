using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            


        }

        protected void ButtonSubmit_Click(object sender, EventArgs e)
        {
            string userName = WebConfigurationManager.AppSettings["Username"];
            string passWord= WebConfigurationManager.AppSettings["Password"];
            if (txtEmail.Text == userName && txtPwd.Text == passWord)
            {
                Session.Add("UserId", userName);
                Response.Redirect("/Admin.aspx");
            }
            else
            {
                lbMsg.Text = "Email Id or Password is incorrect";
                txtEmail.Text = "";
                txtPwd.Text = "";
            }
        }
    }
}