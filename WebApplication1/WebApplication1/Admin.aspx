<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Admin.aspx.cs" Inherits="WebApplication1.AdminPannel" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div class="container jumbotron">
         <h2 class="text-center"style="color:red">Admin Control Panel</h2>
        <br />

        <div class ="row">
<asp:Table ID="Table1" runat="server" CellPadding="0" CssClass="table table-borderless" BorderColor="DarkTurquoise" BackColor="DarkTurquoise" ForeColor="Black" BorderWidth="0">
    <asp:TableRow>
        <asp:TableCell>Default Page Text 1</asp:TableCell>
        <asp:TableCell><asp:TextBox ID="Text1" runat="server" Class="form-control"></asp:TextBox></asp:TableCell>
    </asp:TableRow>
    <asp:TableRow>
        <asp:TableCell>Default Page Text 2</asp:TableCell>
        <asp:TableCell><asp:TextBox ID="Text2" runat="server" Class="form-control"></asp:TextBox></asp:TableCell>
    </asp:TableRow>
    <asp:TableRow>
        <asp:TableCell>Header Text</asp:TableCell>
        <asp:TableCell>
            <asp:TextBox ID="Header1" runat="server" Class="form-control"></asp:TextBox></asp:TableCell>
    </asp:TableRow>
    <asp:TableRow>
        <asp:TableCell>Footer Text</asp:TableCell>
        <asp:TableCell>
            <asp:TextBox ID="Header2" runat="server" Class="form-control"></asp:TextBox></asp:TableCell>
    </asp:TableRow>
    
</asp:Table>
            <br />

</div>
        <div class="row ">
            <div class="col text-center">
<asp:Button ID="ButtonSubmit" runat="server" class="btn btn-success" Text="Save Settings" OnClick="ButtonSubmit_Click" />
            </div>
            
        </div>
  </div>
</asp:Content>
