<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="WebApplication1.Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <style>
        .LoginLabel {
            position: relative;
            left: 100px;
        }
    </style>
    <style>
        .LoginLabel1 {
            position: relative;
            left: 75px;
        }
    </style>

    <div class="container jumbotron ">

        <h2 class="LoginLabel" style="color:red">Login Page </h2>
        <br />
        <br />
        <%--<input type="password" class="form-control" id="pwd" placeholder="Enter password" name="pwd">--%>
        <div class="row  LoginLabel1">
            <div class="form-group">

                <label for="txtEmail">Email:</label>
                <asp:TextBox ID="txtEmail" runat="server" Class="form-control  " placeholder="Enter email"></asp:TextBox>
                <%--<button type="submit" class="btn btn-default">Submit</button>--%>
                <br />

                <label for="txtPwd">Password:</label>
                <asp:TextBox ID="txtPwd" runat="server" Class="form-control" placeholder="Enter password" TextMode="Password"></asp:TextBox>
                <%--</form>--%>
                <br />
                <br />
            </div>
        </div>
        <div class="row ">
            <div class="text-center">
                <asp:Button ID="ButtonSubmit" runat="server" Text="submit" Class="btn btn-default " OnClick="ButtonSubmit_Click" />
            </div>
            <br />
            <div class="text-center">
                <asp:Label ID="lbMsg" runat="server" ForeColor="Red"></asp:Label>
            </div>
        </div>


    </div>
</asp:Content>
