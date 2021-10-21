import { InputText } from "./components";

function App() {
  return (
    <>
      <h1>
        lab3
      </h1>
      <InputText onSubmit={() => {console.log("hehe")}}>
      </InputText>
    </>
  );
}

export default App;
