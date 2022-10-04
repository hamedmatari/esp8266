#include <iostream.h>

const string PAGE_MAIN = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Ostad Babai</title>
  </head>
  <style>
    *,
    *::before,
    *::after {
      box-sizing: border-box;
      font-family: Arial, Helvetica, sans-serif;
    }

    :root {
      --primary-light-hsl: 200, 100%, 91%;
      --primary-hsl: 200, 100%, 50%;
      --primary-dark-hsl: 200, 100%, 6%;
      --success-hsl: 100, 60%, 50%;
      --error-hsl: 0, 60%, 50%;
    }
    .page {
      padding-top: 10%;
      /* display: flex; */
      justify-content: center;
      align-items: center;
      display: none;
    }
    body {
      margin: 0;
    }

    .full-screen-container {
      /* background-image: url("background-image.jpg");
      background-size: cover;
      background-position: center; */
      /* background-color: #b6c9e3; */
      background-color: #c5cddc;
      height: 100vh;
      width: 100vw;
      display: flex;
      justify-content: center;
      align-items: center;
    }

    .login-container {
      --color: hsl(var(--primary-dark-hsl), 0.7);
      background-color: var(--color);
      box-shadow: 0 0 15px 0 var(--color);
      padding: 40px 30px;
      width: 80%;
      max-width: 600px;
      border-radius: 20px;
    }

    .login-title {
      margin: 0;
      color: white;
      text-align: center;
      font-size: 2rem;
      font-weight: normal;
    }

    .form {
      display: flex;
      flex-direction: column;
      gap: 20px;
      margin-top: 40px;
    }

    .input-group {
      display: flex;
      flex-direction: column;
      gap: 7px;
    }

    .input-group label {
      color: white;
      font-weight: lighter;
    }

    .input-group input {
      font-size: 1.25rem;
      padding: 0.5em;
      background-color: hsl(var(--primary-light-hsl), 0.3);
      border: none;
      outline: none;
      border-radius: 0.25em;
      color: white;
      font-weight: lighter;
    }

    /* .input-group.success input {
      box-shadow: 0 0 0 1px hsl(var(--success-hsl));
    }
    
    .input-group.error input {
      box-shadow: 0 0 0 1px hsl(var(--error-hsl));
    } */

    .input-group input:focus {
      box-shadow: 0 0 0 1px hsl(var(--primary-hsl));
    }

    .input-group .msg {
      display: none;
      font-size: 0.75rem;
    }

    .input-group.success .msg,
    .input-group.error .msg {
      display: block;
    }

    /* .input-group.error .msg {
      color: hsl(var(--error-hsl));
    } */

    .input-group.success .msg {
      color: hsl(var(--success-hsl));
    }

    .login-button {
      padding: 0.5em 1em;
      font-size: 1.5rem;
      font-weight: lighter;
      color: white;
      background-color: hsl(var(--primary-hsl), 0.25);
      border: 1px solid hsl(var(--primary-hsl));
      border-radius: 0.25em;
      outline: none;
      cursor: pointer;
    }

    .login-button:hover,
    .login-button:focus {
      background-color: hsl(var(--primary-hsl), 0.4);
    }
    table {
      font-family: "Helvetica Neue", Helvetica, sans-serif;
      box-shadow: rgba(17, 17, 26, 0.1) 0px 1px 0px,
        rgba(17, 17, 26, 0.1) 0px 8px 24px, rgba(17, 17, 26, 0.1) 0px 16px 48px;
    }

    caption {
      text-align: left;
      color: silver;
      font-weight: bold;
      text-transform: uppercase;
      padding: 5px;
    }

    thead {
      background: SteelBlue;
      color: white;
    }

    th,
    td {
      padding: 5px 10px;
    }

    tbody tr:nth-child(even) {
      background: WhiteSmoke;
    }

    tbody tr td:nth-child(2) {
      text-align: center;
    }

    tbody tr td:nth-child(3),
    tbody tr td:nth-child(4) {
      text-align: right;
      font-family: monospace;
    }

    tfoot {
      background: SeaGreen;
      color: white;
      text-align: right;
    }

    tfoot tr th:last-child {
      font-family: monospace;
    }

    .toggle-button-cover {
      display: table-cell;
      position: relative;
      width: 100px;
      height: 70px;
      /*   background:red; */
      box-sizing: border-box;
    }

    .button-cover {
      height: 50px;
      margin: 10px;
      /*   background-color: transparent; */
      /*   box-shadow: 0 10px 20px -8px #c5d6d6; */
      border-radius: 4px;
    }

    .button-cover,
    .knobs,
    .layer {
      position: absolute;
      top: 0;
      right: 0;
      bottom: 0;
      left: 0;
    }

    .button {
      position: relative;
      top: 50%;
      width: 74px;
      /*   background:blue; */
      height: 36px;
      margin: -20px auto 0 auto;
      overflow: hidden;
    }

    .button.r,
    .button.r .layer {
      border-radius: 100px;
    }
    .checkbox {
      position: relative;
      width: 100%;
      height: 100%;
      padding: 0;
      margin: 0;
      opacity: 0;
      cursor: pointer;
      z-index: 3;
    }

    .knobs {
      z-index: 2;
    }

    .layer {
      width: 100%;
      background-color: #ebf7fc;
      transition: 0.3s ease all;
      z-index: 1;
    }

    /* Button 1 */
    #button-1 .knobs:before {
      content: "YES";
      position: absolute;
      top: 4px;
      left: 4px;
      width: 28px;
      height: 28px;
      color: #fff;
      font-size: 10px;
      font-weight: bold;
      text-align: center;
      line-height: 1;
      padding: 9px 4px;
      background-color: #03a9f4;
      border-radius: 50%;
      transition: 0.3s cubic-bezier(0.18, 0.89, 0.35, 1.15) all;
    }

    #button-1 .checkbox:checked + .knobs:before {
      content: "NO";
      left: 42px;
      background-color: #f44336;
    }

    #button-1 .checkbox:checked ~ .layer {
      background-color: #fcebeb;
    }

    #button-1 .knobs,
    #button-1 .knobs:before,
    #button-1 .layer {
      transition: 0.3s ease all;
    }
  </style>

  <body>
    <div class="page" id="tablePage">
      <table>
        <thead>
          <tr>
            <th>Saturday</th>
            <th>Sunday</th>
            <th>Monday</th>
            <th>Tuesday</th>
            <th>Wednesday</th>
            <th>Thurday</th>
            <th>Friday</th>
          </tr>
        </thead>
        <tbody id="tableBody">
          <tr>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="1" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="2" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="3" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="4" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="5" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="6" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="7" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
          </tr>
          <tr>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="8" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="9" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="10" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="11" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="12" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="13" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="14" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
          </tr>
          <tr>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="15" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="16" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="17" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="18" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="19" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="20" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="21" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
          </tr>
          <tr>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="22" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="23" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="24" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="25" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="26" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="27" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="28" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
          </tr>
          <tr>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="29" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="30" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="31" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="32" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="33" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="34" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
            <td>
              <div class="container">
                <div class="toggle-button-cover">
                  <div class="button-cover">
                    <div class="button r" id="button-1">
                      <input id="35" type="checkbox" class="checkbox" />
                      <div class="knobs"></div>
                      <div class="layer"></div>
                    </div>
                  </div>
                </div>
              </div>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
    <form
      class="full-screen-container"
      id="login-form"
      onsubmit="handleClickLogin()"
    >
      <div class="login-container">
        <h1 class="login-title">Welcome</h1>
        <div class="form">
          <div class="input-group success">
            <label for="username">Username</label>
            <input name="username" id="username" />
            <!-- <span class="msg">Valid email</span> -->
          </div>

          <div class="input-group error">
            <label for="password">Password</label>
            <input type="password" name="password" id="password" />
            <!-- <span class="msg">Incorrect password</span> -->
          </div>

          <button id="login-btn" type="submit" class="login-button">
            Login
          </button>
        </div>
      </div>
    </form>
  </body>
  <script>
    let myHeaders = {};
    const username = document.getElementById("username");
    const password = document.getElementById("password");
    const switches = document.querySelectorAll(".checkbox");
    function fetcher(url, option = {}) {
      console.log(option);
      return fetch(url, {
        headers: { ...option, myHeaders },
      });
    }
    function handleClickLogin(e) {
      e.preventDefault();
      // console.log(username.value);
      // console.log(password.value);
      fetch(`/login?username=${username.value}&password=${password.value}`)
        .then((response) => {
          if (response.ok) {
            return response;
          }
          return Promise.reject(response);
        })
        .then((res) => {
          console.log("res");
          myHeaders = new Headers({
            athenticate: `${username.value}:${password.value}`,
          });
        })
        .catch((err) => {
          console.log("err");
          alert("error");
        });
      if (username.value === "hamed") {
        document.getElementById("login-form").style.display = "none";
        document.getElementById("tablePage").style.display = "flex";
        for (const checkbox of switches) {
          if (checkbox.id === "5" || checkbox.id === "3") {
            // checkbox.setAttribute("checked", "true");
            checkbox.checked = true;
            console.log(checkbox);
          }
          checkbox.addEventListener("click", handleClickSwitch);
        }
      }
    }
    function handleClickSwitch(e) {
      console.log(e.target);
      console.log(e.target.checked);

      fetcher(`/check?${e.target.id}=${e.target.checked}`);
    }

    document
      .getElementById("login-btn")
      .addEventListener("click", handleClickLogin);
  </script>
</html>
)=====";
