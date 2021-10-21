function InputText({ onSubmit }) {
    return (
        <form onSubmit={onSubmit}>
            <input type="text" />
            <button type="submit">Search!</button>
        </form>

    );
}

export { InputText };
